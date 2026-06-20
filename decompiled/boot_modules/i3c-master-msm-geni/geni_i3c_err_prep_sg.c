__int64 __fastcall geni_i3c_err_prep_sg(__int64 a1)
{
  __int64 v2; // x21
  int v3; // w8
  __int64 (*v4)(void); // x8
  __int64 result; // x0
  char v6; // w8
  unsigned int v7; // w20
  __int64 v8; // x3
  __int64 v9; // x0

  v2 = a1 + 20480;
  if ( !*(_DWORD *)(a1 + 104) )
  {
    v3 = *(unsigned __int8 *)(a1 + 21240);
    if ( v3 != 1 )
    {
      result = 0;
      if ( !v3 )
        return result;
      goto LABEL_8;
    }
  }
  v4 = *(__int64 (**)(void))(**(_QWORD **)(a1 + 2800) + 336LL);
  if ( !v4 )
  {
    v7 = -38;
LABEL_16:
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s:gpi dma terminate failed ret:%d\n", "geni_i3c_err_prep_sg", v7);
    v9 = *(_QWORD *)(a1 + 8);
    if ( v9 )
      dev_err(v9, "%s:gpi dma terminate failed ret:%d\n", "geni_i3c_err_prep_sg", v7);
    else
      printk(&unk_13118, "geni_i3c_err_prep_sg", v7, v8);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
    result = v7;
    goto LABEL_7;
  }
  if ( *((_DWORD *)v4 - 1) != -403578064 )
    __break(0x8228u);
  result = v4();
  if ( (_DWORD)result )
  {
    v7 = result;
    goto LABEL_16;
  }
LABEL_7:
  v6 = *(_BYTE *)(v2 + 760);
  *(_BYTE *)(v2 + 761) = 0;
  if ( (v6 & 1) == 0 )
    return result;
LABEL_8:
  if ( !*(_DWORD *)(a1 + 104) )
  {
    result = 4294967291LL;
    *(_DWORD *)(a1 + 104) = -5;
  }
  *(_BYTE *)(v2 + 760) = 0;
  return result;
}
