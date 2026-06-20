__int64 __fastcall geni_i2c_gpi_pause_resume(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 (*v5)(void); // x8
  int v6; // w8
  __int64 (*v7)(void); // x9
  unsigned int v8; // w21

  result = *(_QWORD *)(a1 + 5120);
  if ( !result )
    return result;
  if ( (a2 & 1) == 0 )
  {
    v6 = *(unsigned __int8 *)(a1 + 9196);
    if ( v6 == 1 )
      *(_DWORD *)(a1 + 8872) = 5;
    v7 = *(__int64 (**)(void))(*(_QWORD *)result + 328LL);
    if ( v7 )
    {
      if ( *((_DWORD *)v7 - 1) != -403578064 )
        __break(0x8229u);
      result = v7();
      if ( (*(_BYTE *)(a1 + 9196) & 1) == 0 )
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
    *(_DWORD *)(a1 + 8872) = 0;
    *(_BYTE *)(a1 + 9196) = 0;
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
  ipc_log_string(*(_QWORD *)(a1 + 5096), "%s failed: tx:%d status:%d\n", "geni_i2c_gpi_pause_resume", result, a2 & 1);
  if ( *(_QWORD *)a1 )
    dev_err(*(_QWORD *)a1, "%s failed: tx:%d status:%d\n", "geni_i2c_gpi_pause_resume", v8, a2 & 1);
  else
    printk(&unk_F1C7, "geni_i2c_gpi_pause_resume", v8);
  if ( *(_QWORD *)a1 )
    i2c_trace_log();
  return 4294967274LL;
}
