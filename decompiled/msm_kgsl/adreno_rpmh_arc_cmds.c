__int64 __fastcall adreno_rpmh_arc_cmds(__int64 a1, __int64 a2)
{
  __int64 aux_data; // x0
  unsigned __int64 v4; // x9
  unsigned __int64 v5; // x9
  unsigned int v6; // w8
  unsigned __int64 v7; // x11
  char v8; // w10
  bool v9; // zf
  bool v10; // w12
  int v11; // w11
  __int64 result; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  aux_data = cmd_db_read_aux_data(a2, v13);
  v4 = v13[0];
  *(_QWORD *)(a1 + 8) = aux_data;
  *(_DWORD *)a1 = 1;
  if ( v4 < 4 )
  {
    result = 4294967235LL;
  }
  else
  {
    v5 = v4 >> 1;
    v6 = 0;
    v7 = 1;
    v8 = 1;
    do
    {
      v11 = *(unsigned __int16 *)(aux_data + 2 * v7);
      if ( *(_WORD *)(aux_data + 2LL * v6) && !v11 )
        break;
      v9 = v11 == 0;
      v7 = v6 + 2;
      ++v6;
      v10 = v9;
      *(_DWORD *)a1 = v7;
      v8 &= v10;
    }
    while ( v5 > v7 );
    if ( (v8 & 1) != 0 )
      result = 4294967235LL;
    else
      result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
