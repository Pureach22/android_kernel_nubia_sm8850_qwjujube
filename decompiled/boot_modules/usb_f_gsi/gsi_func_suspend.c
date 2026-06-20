__int64 __fastcall gsi_func_suspend(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x0
  void *v5; // x3
  char v6; // w8

  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 1344);
    if ( *(_QWORD *)a1 )
      v5 = *(void **)a1;
    else
      v5 = &unk_1069E;
    ipc_log_string(v4, "func susp %u cmd for %s", a2, v5);
  }
  if ( (a2 & 1) != 0 )
  {
    v6 = *(_BYTE *)(a1 + 284);
    *(_BYTE *)(a1 + 285) = (a2 & 2) != 0;
    if ( (v6 & 1) == 0 )
    {
      gsi_suspend(a1);
      *(_BYTE *)(a1 + 284) = 1;
    }
  }
  else
  {
    if ( *(_BYTE *)(a1 + 284) == 1 )
    {
      *(_BYTE *)(a1 + 284) = 0;
      gsi_resume(a1);
    }
    *(_BYTE *)(a1 + 285) = (a2 & 2) != 0;
  }
  return 0;
}
