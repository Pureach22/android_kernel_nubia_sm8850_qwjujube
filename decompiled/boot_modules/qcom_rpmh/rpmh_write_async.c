__int64 __fastcall rpmh_write_async(__int64 a1, unsigned int a2, void *src, int a4)
{
  unsigned int v4; // w8
  __int64 v5; // x8
  __int64 v6; // x20
  __int64 v7; // x21
  int v8; // w23
  void *v9; // x24
  char v10; // w25
  __int64 v11; // x20
  unsigned int v12; // w21
  int v13; // w22
  __int64 v15; // [xsp+0h] [xbp-F0h] BYREF
  __int64 v16; // [xsp+8h] [xbp-E8h]
  _QWORD *v17; // [xsp+10h] [xbp-E0h]
  _QWORD v18[27]; // [xsp+18h] [xbp-D8h] BYREF

  v18[26] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v18, 0, 200);
  v16 = 0;
  v15 = a2;
  v17 = v18;
  v18[25] = a1;
  if ( (rpmh_standalone & 1) != 0 )
  {
    v4 = 0;
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 96);
    HIDWORD(v15) = 0;
    v6 = *(_QWORD *)(v5 + 152);
    if ( a2 != 2 )
      goto LABEL_7;
    if ( (*(_BYTE *)(v6 + 1160) & 1) == 0 )
      goto LABEL_7;
    v7 = a1;
    v8 = a4;
    v9 = src;
    raw_spin_lock(v6 + 1152);
    v10 = *(_BYTE *)(v6 + 1157);
    raw_spin_unlock(v6 + 1152);
    src = v9;
    a4 = v8;
    a1 = v7;
    a2 = 2;
    if ( (v10 & 1) != 0 )
    {
      v4 = -16;
    }
    else
    {
LABEL_7:
      v4 = -22;
      if ( src && (unsigned int)(a4 - 17) >= 0xFFFFFFF0 )
      {
        v11 = a1;
        v12 = a2;
        v13 = a4;
        memcpy(v18, src, (unsigned int)(12 * a4));
        v17 = v18;
        LODWORD(v15) = v12;
        LODWORD(v16) = v13;
        v4 = _rpmh_write(v11, v12, &v15);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
