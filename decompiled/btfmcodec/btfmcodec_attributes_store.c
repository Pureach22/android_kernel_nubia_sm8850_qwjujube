__int64 __fastcall btfmcodec_attributes_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x21
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 976);
  v8[0] = 0;
  mutex_lock(v6 + 144);
  LODWORD(a3) = kstrtoll(a3, 0, v8);
  mutex_unlock(v6 + 144);
  _ReadStatusReg(SP_EL0);
  if ( (_DWORD)a3 )
    return -22;
  else
    return a4;
}
