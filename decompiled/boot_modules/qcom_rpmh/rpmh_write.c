__int64 __fastcall rpmh_write(__int64 a1, int a2, void *src, int a4)
{
  unsigned int v4; // w8
  __int64 v6; // x19
  __int64 v7; // x21
  int v8; // w23
  void *v9; // x24
  char v10; // w25
  __int64 v11; // x21
  int v12; // w22
  int v13; // w23
  _QWORD v14[2]; // [xsp+0h] [xbp-110h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-100h] BYREF
  _DWORD v16[2]; // [xsp+20h] [xbp-F0h] BYREF
  __int64 v17; // [xsp+28h] [xbp-E8h]
  _QWORD *v18; // [xsp+30h] [xbp-E0h]
  _QWORD v19[27]; // [xsp+38h] [xbp-D8h] BYREF

  v19[26] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19[24] = v14;
  v15[0] = v15;
  v15[1] = v15;
  v16[0] = a2;
  v16[1] = 1;
  v14[0] = 0;
  v14[1] = 0;
  v17 = 0;
  v18 = v19;
  memset(v19, 0, 192);
  v19[25] = a1;
  if ( (rpmh_standalone & 1) != 0 )
  {
LABEL_2:
    v4 = 0;
    goto LABEL_3;
  }
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( a2 == 2 && (*(_BYTE *)(v6 + 1160) & 1) != 0 )
  {
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
      goto LABEL_3;
    }
  }
  v4 = -22;
  if ( src )
  {
    if ( (unsigned int)(a4 - 17) >= 0xFFFFFFF0 )
    {
      v11 = a1;
      v12 = a2;
      v13 = a4;
      memcpy(v19, src, (unsigned int)(12 * a4));
      v18 = v19;
      v16[0] = v12;
      LODWORD(v17) = v13;
      v4 = _rpmh_write(v11, v12, (__int64)v16);
      if ( !v4 )
      {
        if ( !(unsigned int)wait_for_completion_timeout(v14, 1250) )
        {
          rpmh_rsc_debug(v6, v14);
          v4 = -110;
          goto LABEL_3;
        }
        goto LABEL_2;
      }
    }
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return v4;
}
