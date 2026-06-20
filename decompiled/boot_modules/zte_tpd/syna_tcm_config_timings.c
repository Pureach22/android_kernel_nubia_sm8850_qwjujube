__int64 __fastcall syna_tcm_config_timings(_DWORD *a1, _DWORD *a2, __int64 a3, int a4)
{
  int v4; // w8

  if ( !a2 && a4 == 0xFFFF )
  {
    printk(&unk_3C0B8, "syna_tcm_config_timings", a3);
    return 4294967055LL;
  }
  else
  {
    if ( a2 && (a4 & 4) != 0 )
    {
      v4 = a2[2];
      if ( v4 )
        a1[132] = v4;
      LODWORD(a3) = a2[3];
      if ( (_DWORD)a3 )
        a1[133] = a3;
    }
    if ( (a4 & 1) != 0 )
    {
      if ( a2 && *a2 )
        LODWORD(a3) = *a2;
      if ( (_DWORD)a3 )
        a1[130] = a3;
    }
    if ( (a4 & 2) != 0 )
    {
      if ( a2 && a2[1] )
        LODWORD(a3) = a2[1];
      if ( (_DWORD)a3 )
        a1[131] = a3;
    }
    if ( a2 )
    {
      if ( (a4 & 8) != 0 )
      {
        LODWORD(a3) = a2[4];
        if ( (_DWORD)a3 )
          a1[134] = a3;
      }
    }
    if ( (a4 & 0x100) != 0 )
    {
      if ( a2 && a2[8] )
        LODWORD(a3) = a2[8];
      if ( (_DWORD)a3 )
        a1[122] = a3;
    }
    if ( (a4 & 0x200) != 0 )
    {
      if ( a2 && a2[9] )
        LODWORD(a3) = a2[9];
      if ( (_DWORD)a3 )
        a1[123] = a3;
    }
    return 0;
  }
}
