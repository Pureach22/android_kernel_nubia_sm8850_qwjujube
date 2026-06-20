__int64 __fastcall enable_ts_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x9
  __int64 v7; // x22
  int v8; // w8
  __int64 result; // x0
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x9
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 96);
  v13[0] = 0;
  v7 = *(_QWORD *)(v6 + 152);
  v8 = kstrtoull(a3, 0, v13);
  result = -22;
  if ( !v8 && v13[0] <= 1u )
  {
    raw_spin_lock(v7 + 24);
    v10 = *(_DWORD *)(a2 + 32);
    if ( v10 == 4 )
    {
      v11 = 360;
      v12 = 40;
    }
    else
    {
      if ( v10 != 9 )
      {
        a4 = -22;
        if ( v7 == -24 )
          goto LABEL_9;
        goto LABEL_8;
      }
      v11 = 164;
      v12 = 48;
    }
    *(_BYTE *)(*(_QWORD *)(v7 + v12) + v11) = v13[0] != 0;
    if ( v7 == -24 )
    {
LABEL_9:
      result = a4;
      goto LABEL_10;
    }
LABEL_8:
    raw_spin_unlock(v7 + 24);
    goto LABEL_9;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
