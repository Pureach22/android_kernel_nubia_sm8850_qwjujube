char *__fastcall target_if_cfr_default_ta_ra_config(char *result, char a2, unsigned __int16 a3)
{
  char *v4; // x20
  char v5; // w21
  __int64 v6; // x23
  char *v7; // x26
  int v8; // w9
  int v9; // w11
  unsigned __int64 v10; // [xsp+0h] [xbp-20h]
  int v11; // [xsp+8h] [xbp-18h] BYREF
  __int16 v12; // [xsp+Ch] [xbp-14h]
  int v13; // [xsp+10h] [xbp-10h] BYREF
  __int16 v14; // [xsp+14h] [xbp-Ch]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v4 = result;
  v5 = 0;
  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = -560;
  v10 = a3;
  v14 = -1;
  v13 = -1;
  v12 = 0;
  v11 = 0;
  do
  {
    if ( ((v10 >> v5) & 1) != 0 )
    {
      v7 = &v4[v6];
      qdf_mem_copy(&v4[v6 + 597], &v11, 6u);
      qdf_mem_copy(&v4[v6 + 609], &v13, 6u);
      qdf_mem_copy(&v4[v6 + 603], &v11, 6u);
      result = (char *)qdf_mem_copy(&v4[v6 + 615], &v13, 6u);
      v8 = *(_DWORD *)&v4[v6 + 587];
      if ( (a2 & 1) != 0 )
        v9 = 33505231;
      else
        v9 = 16335;
      *(_DWORD *)(v7 + 591) = 0;
      *(_WORD *)(v7 + 595) = 0;
      *(_DWORD *)(v7 + 587) = v8 & 0xFE00C000 | v9;
    }
    v6 += 35;
    ++v5;
  }
  while ( v6 );
  _ReadStatusReg(SP_EL0);
  return result;
}
