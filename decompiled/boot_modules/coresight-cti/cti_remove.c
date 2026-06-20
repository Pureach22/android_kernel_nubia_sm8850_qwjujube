__int64 __fastcall cti_remove(__int64 a1)
{
  __int64 v1; // x19
  _QWORD *i; // x21
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 result; // x0
  _QWORD v6[5]; // [xsp+8h] [xbp-28h] BYREF

  v6[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(&ect_mutex);
  for ( i = *(_QWORD **)(v1 + 24); i != (_QWORD *)(v1 + 24); i = (_QWORD *)*i )
  {
    if ( *(i - 2) )
    {
      v3 = *(_QWORD *)(v1 + 8);
      v6[0] = v3;
      v6[1] = *(i - 1);
      v4 = *(_QWORD *)(v3 + 168);
      v6[2] = *(i - 2);
      if ( !v4 )
        v4 = *(_QWORD *)(v3 + 56);
      v6[3] = v4;
      coresight_remove_sysfs_link(v6);
      *(i - 2) = 0;
    }
  }
  mutex_unlock(&ect_mutex);
  result = coresight_unregister(*(_QWORD *)(v1 + 8));
  _ReadStatusReg(SP_EL0);
  return result;
}
