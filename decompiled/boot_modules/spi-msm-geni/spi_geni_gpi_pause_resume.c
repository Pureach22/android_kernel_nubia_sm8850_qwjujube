__int64 __fastcall spi_geni_gpi_pause_resume(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 (*v5)(void); // x8
  int v6; // w8
  __int64 (*v7)(void); // x9
  int v8; // w21
  __int64 v9; // x0

  result = *(_QWORD *)(a1 + 320);
  if ( !result )
    return result;
  if ( (a2 & 1) == 0 )
  {
    v6 = *(unsigned __int8 *)(a1 + 580);
    if ( v6 == 1 )
      *(_DWORD *)(a1 + 336) = 5;
    v7 = *(__int64 (**)(void))(*(_QWORD *)result + 328LL);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -403578064 )
        __break(0x8229u);
      result = v7();
      if ( (*(_BYTE *)(a1 + 580) & 1) == 0 )
      {
LABEL_16:
        if ( !(_DWORD)result )
          return result;
        goto LABEL_19;
      }
    }
    else
    {
      result = 4294967258LL;
      if ( !v6 )
        goto LABEL_19;
    }
    *(_DWORD *)(a1 + 336) = 0;
    *(_BYTE *)(a1 + 580) = 0;
    goto LABEL_16;
  }
  v5 = *(__int64 (**)(void))(*(_QWORD *)result + 320LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -403578064 )
      __break(0x8228u);
    result = v5();
    goto LABEL_16;
  }
  LODWORD(result) = -38;
LABEL_19:
  v8 = result;
  ipc_log_string(*(_QWORD *)(a1 + 472), "%s failed: tx:%d status:%d\n", "spi_geni_gpi_pause_resume", result, a2 & 1);
  v9 = *(_QWORD *)(a1 + 200);
  if ( v9 )
    dev_err(v9, "%s failed: tx:%d status:%d\n", "spi_geni_gpi_pause_resume", v8, a2 & 1);
  else
    printk(&unk_DE93);
  if ( *(_QWORD *)(a1 + 200) )
    spi_trace_log();
  return 4294967274LL;
}
