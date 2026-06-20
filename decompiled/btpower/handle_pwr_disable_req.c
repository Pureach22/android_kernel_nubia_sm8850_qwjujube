__int64 __fastcall handle_pwr_disable_req(int a1, int a2, int a3, int a4)
{
  __int64 v5; // x9
  __int64 v8; // x25
  __int64 v9; // x24
  __int64 result; // x0
  __int64 v11; // x26
  __int64 v12; // x28
  __int64 v13; // x8
  unsigned int v14; // w23

  if ( a2 < 1 )
    return 0;
  v5 = 80;
  if ( a1 == 1 )
    v5 = 64;
  v8 = 48LL * (unsigned int)a2;
  v9 = 0;
  LODWORD(result) = 0;
  if ( a1 )
    v11 = v5;
  else
    v11 = 56;
  do
  {
    v12 = *(_QWORD *)(pwr_data + v11);
    v13 = v12 + v9;
    if ( a4 && *(_BYTE *)(v13 + 40) == 1 )
    {
      v14 = result;
      if ( a3 )
      {
        if ( v13 && *(_BYTE *)(v12 + v9 + 28) == 1 && *(_BYTE *)(v12 + v9 + 29) == 1 )
          vreg_configure(v12 + v9, 0);
        printk(&unk_12817, "handle_pwr_disable_req");
      }
      printk(&unk_11EA1, "handle_pwr_disable_req");
      result = v14;
    }
    else
    {
      result = vreg_disable(v12 + v9);
    }
    v9 += 48;
  }
  while ( v8 != v9 );
  return result;
}
