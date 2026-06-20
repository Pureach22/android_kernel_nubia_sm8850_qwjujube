__int64 __fastcall syna_tcm_wait_for_report(__int64 a1, unsigned __int8 a2, __int64 a3, int a4, unsigned int a5)
{
  __int64 v6; // x2
  __int64 v8; // x23
  unsigned __int8 v11; // w24
  _DWORD *v12; // x8
  int v13; // w23
  bool v14; // w25
  void *v15; // x0
  __int64 result; // x0
  unsigned __int8 v17; // w23
  int v18; // w23
  unsigned int v19; // w24
  __int64 v20; // x2
  __int64 v21; // x22
  unsigned int v22; // w25
  void (__fastcall *v23)(__int64, __int64); // x8
  unsigned int v24; // w21
  unsigned __int8 v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  if ( !a1 )
  {
    v15 = unk_3365A;
LABEL_12:
    printk(v15, "syna_tcm_wait_for_report", a3);
LABEL_14:
    result = 4294967055LL;
    goto LABEL_35;
  }
  if ( !a3 )
  {
    v15 = unk_3A4C0;
    goto LABEL_12;
  }
  v6 = *(unsigned __int8 *)(a1 + 9);
  if ( (_DWORD)v6 != 1 )
  {
    printk(unk_33E1E, "syna_tcm_wait_for_report", v6);
    goto LABEL_14;
  }
  v8 = *(_QWORD *)(a1 + 72);
  if ( *(_BYTE *)(v8 + 20) != 1 )
    goto LABEL_16;
  if ( !v8 )
  {
    v17 = a2;
    printk(unk_37DFA, "syna_tcm_enable_irq", v6);
    a2 = v17;
    goto LABEL_16;
  }
  if ( !*(_QWORD *)(v8 + 56) )
  {
LABEL_16:
    v14 = 1;
    goto LABEL_17;
  }
  v11 = a2;
  mutex_lock(a1 + 80);
  v12 = *(_DWORD **)(v8 + 56);
  if ( *(v12 - 1) != 875454897 )
    __break(0x8228u);
  v13 = ((__int64 (__fastcall *)(__int64, _QWORD))v12)(v8, 0);
  mutex_unlock(a1 + 80);
  a2 = v11;
  v14 = v13 < 1;
LABEL_17:
  v18 = a2;
  v19 = a4;
  if ( a4 >= 1 )
    goto LABEL_20;
  while ( 1 )
  {
    result = syna_tcm_get_event_data(a1, v25, a3);
    if ( (result & 0x80000000) == 0 && v25[0] == v18 && *(_DWORD *)(a3 + 12) )
      break;
    if ( v19 >= a5 )
      break;
    v19 += a4;
    if ( a4 >= 1 )
LABEL_20:
      msleep((unsigned int)a4);
  }
  v21 = *(_QWORD *)(a1 + 72);
  if ( v14 || (*(_BYTE *)(v21 + 20) & 1) == 0 )
  {
LABEL_31:
    if ( v19 < a5 )
      goto LABEL_35;
    goto LABEL_32;
  }
  if ( v21 )
  {
    if ( *(_QWORD *)(v21 + 56) )
    {
      v22 = result;
      mutex_lock(a1 + 80);
      v23 = *(void (__fastcall **)(__int64, __int64))(v21 + 56);
      /* CFI check removed */
      v23(v21, 1);
      mutex_unlock(a1 + 80);
      result = v22;
    }
    goto LABEL_31;
  }
  v24 = result;
  printk(unk_37DFA, "syna_tcm_enable_irq", v20);
  result = v24;
  if ( v19 < a5 )
    goto LABEL_35;
LABEL_32:
  if ( v25[0] != v18 || !*(_DWORD *)(a3 + 12) )
    result = 4294967052LL;
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
