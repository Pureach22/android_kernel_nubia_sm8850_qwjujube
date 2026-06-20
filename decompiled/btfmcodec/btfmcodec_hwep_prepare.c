__int64 __fastcall btfmcodec_hwep_prepare(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, char a5)
{
  __int64 v5; // x19
  __int64 v6; // x23
  __int64 v7; // x8
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 result; // x0
  __int64 v11; // x0
  unsigned int v14; // w22
  unsigned int v15; // w20
  __int64 v16; // x8
  _DWORD *v17; // x8
  unsigned int v18; // w19

  v5 = *(_QWORD *)(a1 + 984);
  if ( !v5 )
    return 0xFFFFFFFFLL;
  v6 = *(_QWORD *)(v5 + 80);
  if ( !v6 )
    return 0xFFFFFFFFLL;
  v7 = *(_QWORD *)(v6 + 112);
  if ( !v7 )
    return 0xFFFFFFFFLL;
  v8 = *(__int64 (__fastcall **)(_QWORD))(v7 + 24);
  if ( !v8 )
    return 0xFFFFFFFFLL;
  v11 = *(_QWORD *)(a1 + 984);
  if ( *((_DWORD *)v8 - 1) != -1018167674 )
    __break(0x8228u);
  v14 = v8(v11);
  printk(&unk_D6FC, "btfmcodec_hwep_prepare");
  result = v14;
  if ( !v14 )
  {
    if ( (*(_QWORD *)(v5 + 104) & 1) != 0 )
    {
      result = btfmcodec_configure_master(a1, a4);
      if ( (result & 0x80000000) != 0 )
      {
        v18 = result;
        printk(&unk_C569, "btfmcodec_hwep_prepare");
        return v18;
      }
    }
    else
    {
      result = 0;
      if ( !a4 || (*(_QWORD *)(v5 + 104) & 2) == 0 )
        return result;
      result = btfmcodec_configure_dma(a1, a4);
      if ( (result & 0x80000000) != 0 )
      {
        v15 = result;
        printk(&unk_C087, "btfmcodec_hwep_prepare");
        v16 = *(_QWORD *)(v6 + 112);
        if ( v16 )
        {
          v17 = *(_DWORD **)(v16 + 8);
          if ( v17 )
          {
            if ( *(v17 - 1) != 1607364836 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD))v17)(v5, a4);
          }
        }
        return v15;
      }
    }
    if ( (a5 & 1) != 0 )
      return result;
    v18 = result;
    btfmcodec_set_current_state(a1 + 912, 2u);
    return v18;
  }
  return result;
}
