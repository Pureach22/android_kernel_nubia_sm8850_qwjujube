__int64 __fastcall set_select_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 v7; // x2
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int64 v10; // [xsp+10h] [xbp-10h] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  v9 = 0;
  v10 = 0;
  v5 = *(_QWORD *)(v4 + 152);
  if ( *(int *)(v5 + 104) >= 64 )
  {
    dev_err(*(_QWORD *)(v5 + 8), " Too many groups are being configured\n", s);
    goto LABEL_8;
  }
  if ( sscanf(s, "%d %d %lx", (char *)&v9 + 4, &v9, &v10) != 3 )
  {
LABEL_8:
    a4 = -22;
    goto LABEL_9;
  }
  raw_spin_lock(v5 + 32);
  if ( SHIDWORD(v9) > *(_DWORD *)(v5 + 40) || (int)v9 > *(_DWORD *)(v5 + 36) )
  {
    dev_err(*(_QWORD *)(v5 + 8), "Invalid select decode data\n", v7);
  }
  else
  {
    *(_QWORD *)(*(_QWORD *)(v5 + 72) + 16LL * *(int *)(v5 + 104)) = 472 * (int)v9 + 4 * HIDWORD(v9) + 96;
    *(_QWORD *)(*(_QWORD *)(v5 + 72) + 16LL * (int)(*(_DWORD *)(v5 + 104))++ + 8) = v10;
  }
  raw_spin_unlock(v5 + 32);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return a4;
}
