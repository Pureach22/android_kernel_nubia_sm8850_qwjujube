__int64 __fastcall set_group_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 v7; // x2
  __int64 v9; // [xsp+0h] [xbp-20h] BYREF
  int v10; // [xsp+Ch] [xbp-14h] BYREF
  int v11; // [xsp+10h] [xbp-10h] BYREF
  int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 96);
  v12 = 0;
  v10 = 0;
  v11 = 0;
  v5 = *(_QWORD *)(v4 + 152);
  v9 = 0;
  if ( *(int *)(v5 + 96) >= 288 )
  {
    dev_err(*(_QWORD *)(v5 + 8), " Too many groups are being configured\n", s);
    goto LABEL_8;
  }
  if ( sscanf(s, "%d %d %d %lx", &v12, &v11, &v10, &v9) != 4 )
  {
LABEL_8:
    a4 = -22;
    goto LABEL_9;
  }
  raw_spin_lock(v5 + 32);
  if ( v12 > 4 || v11 > *(_DWORD *)(v5 + 44) )
  {
    dev_err(*(_QWORD *)(v5 + 8), "Invalid group data\n", v7);
  }
  else
  {
    *(_QWORD *)(*(_QWORD *)(v5 + 56) + 16LL * *(int *)(v5 + 96)) = 96 * v12 + 4 * v11 + 472 * v10 + 116;
    *(_QWORD *)(*(_QWORD *)(v5 + 56) + 16LL * (int)(*(_DWORD *)(v5 + 96))++ + 8) = v9;
  }
  raw_spin_unlock(v5 + 32);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return a4;
}
