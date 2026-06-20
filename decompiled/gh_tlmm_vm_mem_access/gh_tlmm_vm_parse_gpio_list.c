__int64 __fastcall gh_tlmm_vm_parse_gpio_list(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x24
  unsigned int v6; // w0
  __int64 v7; // x23
  unsigned __int64 v8; // x22
  __int64 v9; // x20
  unsigned int v10; // w25
  unsigned __int64 v11; // x27
  unsigned int named_gpio; // w0
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x25
  unsigned int v16; // w8
  unsigned int v18; // w2
  __int64 v19; // x0
  unsigned int v20; // w21
  unsigned __int64 StatusReg; // x25
  __int64 v22; // x26

  v3 = a3;
  v6 = of_count_phandle_with_args(a3, "tlmm-vm-gpio-list", "#gpio-cells");
  if ( (v6 & 0x80000000) != 0 )
  {
    dev_err(a1 + 16, "Invalid number of gpios specified\n");
    return 4294967274LL;
  }
  else
  {
    LODWORD(v7) = v6;
    v8 = 4LL * v6;
    v9 = _kmalloc_noprof(v8, 3264);
    if ( v9 )
    {
      while ( !(_DWORD)v7 )
      {
LABEL_8:
        *(_DWORD *)(a2 + 56) = v7;
        v13 = _kmalloc_noprof(4LL * (unsigned int)v7, 3520);
        *(_QWORD *)(a2 + 40) = v13;
        if ( !v13 )
        {
          v20 = -12;
          goto LABEL_30;
        }
        v14 = _kmalloc_noprof(4LL * (unsigned int)v7, 3520);
        *(_QWORD *)(a2 + 48) = v14;
        if ( !v14 )
        {
          v20 = -12;
LABEL_29:
          kfree(*(_QWORD *)(a2 + 40));
          goto LABEL_30;
        }
        v3 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96);
        if ( !v3 )
        {
          v20 = -12;
LABEL_28:
          kfree(*(_QWORD *)(a2 + 48));
          goto LABEL_29;
        }
        if ( !(_DWORD)v7 )
        {
LABEL_19:
          kfree(v3);
          kfree(v9);
          return 0;
        }
        v15 = 0;
        if ( (int)v7 <= 1 )
          v16 = 1;
        else
          v16 = v7;
        v7 = 4LL * v16;
        while ( v8 > v15 )
        {
          if ( (msm_gpio_get_pin_address(*(unsigned int *)(v9 + v15), v3) & 1) == 0 )
          {
            dev_err(a1 + 16, "Invalid gpio\n");
            kfree(v3);
            v20 = -22;
            goto LABEL_28;
          }
          *(_DWORD *)(*(_QWORD *)(a2 + 40) + v15) = *(_QWORD *)v3;
          *(_DWORD *)(*(_QWORD *)(a2 + 48) + v15) = *(_DWORD *)(v3 + 8) - *(_DWORD *)v3 + 1;
          v15 += 4LL;
          if ( v7 == v15 )
            goto LABEL_19;
        }
LABEL_23:
        __break(1u);
        v8 = 4LL * (unsigned int)v7;
        StatusReg = _ReadStatusReg(SP_EL0);
        v22 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
        v9 = _kmalloc_noprof(v8, 3264);
        *(_QWORD *)(StatusReg + 80) = v22;
        if ( !v9 )
          return 4294967284LL;
      }
      v10 = 0;
      v11 = 0;
      while ( 1 )
      {
        named_gpio = of_get_named_gpio(v3, "tlmm-vm-gpio-list", v10);
        if ( (named_gpio & 0x80000000) != 0 )
          break;
        if ( v8 <= v11 )
          goto LABEL_23;
        *(_DWORD *)(v9 + v11) = named_gpio;
        v11 += 4LL;
        ++v10;
        if ( 4LL * (unsigned int)v7 == v11 )
          goto LABEL_8;
      }
      v18 = named_gpio;
      v19 = a1 + 16;
      v20 = v18;
      dev_err(v19, "Failed to receive shared gpios %d\n", v18);
LABEL_30:
      kfree(v9);
      return v20;
    }
    else
    {
      return 4294967284LL;
    }
  }
}
