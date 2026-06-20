# ZTE Power Supply Wrapper Subsystem — Reverse Engineering Analysis

## Driver: `zte_power_supply.ko`
**Source ROM:** REDMAGICOS11.0.18MR1_GB (NX809J)  
**Decompiled files:** 52 (diretório `decompiled/zte_power_supply/`)  
**Reconstruction status:** ✅ Completo — Compilação sem erros, zero símbolos proprietários

---

## Propósito do Driver

O `zte_power_supply.ko` é um subsistema wrapper que encapsula a funcionalidade de gerenciamento de fontes de alimentação (power supply) do Linux kernel. A ZTE criou esta camada de abstração separada da `struct power_supply` padrão do GKI para:

1. Manter hooks proprietários de carregamento (charge policy) independentes do subsistema upstream
2. Fornecer uma API unificada (`zte_power_supply_register`, `zte_power_supply_get_property`, etc.) para drivers internos como `zte_charger_policy.ko`
3. Implementar notificações assíncronas de mudança de estado via workqueues e notifier chains

---

## Estruturas Mapeadas via Ghidra

### `struct zte_power_supply_desc` (80 bytes)

| Offset | Membro | Tipo |
|--------|--------|------|
| 0 | `name` | `const char *` |
| 8 | `type` | `enum power_supply_type` |
| 16 | `supplied_from` | `const char **` |
| 24 | `num_supplicants` | `size_t` |
| 32 | `properties` | `const enum power_supply_property *` |
| 40 | `num_properties` | `size_t` |
| 48 | `get_property` | `int (*)(psy, psp, val)` |
| 56 | `set_property` | `int (*)(psy, psp, val)` |
| 64 | `property_is_writeable` | `int (*)(psy, psp)` |
| 72 | `external_power_changed` | `void (*)(psy)` |

### `struct zte_power_supply` (~1120 bytes)

| Offset | Membro | Tipo |
|--------|--------|------|
| 0 | `desc` | `const struct zte_power_supply_desc *` |
| 8 | `num_supplicants` | `int` |
| 16 | `supplied_from` | `const char **` |
| 40 | `fwnode` | `struct fwnode_handle *` |
| 48 | `drvdata` | `void *` |
| 56 | `dev` | `struct device` |
| 968 | `changed_work` | `struct work_struct` |
| 1000 | `deferred_register_work` | `struct delayed_work` |
| 1104 | `lock` | `spinlock_t` |
| 1108 | `event_pending` | `bool` |
| 1109 | `changed` | `bool` |
| 1112 | `use_cnt` | `atomic_t` |

### Sysfs Attribute Table (`zte_power_supply_attrs`)

- **19 propriedades** expostas no sysfs (índices 0–18 da `enum power_supply_property`)
- Cada entrada: `struct power_supply_attr` de **88 bytes** (11 QWORDs)
- `dev_attr` começa no offset 40 de cada entrada
- Índice calculado via multiplicação pelo inverso modular de 11 (0xBA2E8BA3)

---

## CFI (Control Flow Integrity) — Travas Proprietárias Removidas

O binário original continha verificações de integridade de ponteiros de função:

| Callback | Offset | Assinatura CFI | Hex |
|----------|--------|----------------|-----|
| `get_property` | desc+48 | -2056590187 | `0x856b3e95` |
| `set_property` | desc+56 | 469858761 | `0x1C0181C9` |
| `property_is_writeable` | desc+64 | 1057561745 | `0x3F090491` |
| `external_power_changed` | desc+72 | 1866051055 | `0x6F3AFDEF` |

Estas verificações geravam `__break(0x8228u)` (Kernel Panic) em caso de mismatch.
**Status:** Todas removidas na reconstrução. Callbacks são chamados diretamente após validação de NULL.

---

## Símbolos Exportados (API Pública)

```
zte_power_supply_register
zte_power_supply_register_no_ws
zte_power_supply_unregister
zte_power_supply_changed
zte_power_supply_get_property
zte_power_supply_set_property
zte_power_supply_property_is_writeable
zte_power_supply_get_by_name
zte_power_supply_put
zte_power_supply_get_by_phandle
zte_power_supply_get_by_phandle_array
zte_power_supply_get_drvdata
zte_power_supply_reg_notifier
zte_power_supply_unreg_notifier
zte_devm_power_supply_register
zte_devm_power_supply_register_no_ws
zte_devm_power_supply_put
```

---

## Validação

- **Compilação:** ✅ Zero erros, zero warnings
- **Símbolos indefinidos:** ✅ Todos são APIs padrão do kernel GKI (device model, workqueue, spinlock, OF, PM, notifier)
- **Stubs falsos:** ❌ Nenhum — toda lógica foi reconstruída 1-a-1 do Ghidra
