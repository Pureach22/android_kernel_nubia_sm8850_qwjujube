__int64 __fastcall msm_gem_aspace_domain_attach_detach_update(__int64 result, char a2)
{
  __int64 v2; // x19
  _QWORD *i; // x20
  void (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x0
  _QWORD *v7; // x21
  __int64 *j; // x22
  _QWORD *k; // x20
  _DWORD *v10; // x8
  __int64 v11; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v2 = result;
    v12[0] = 0;
    mutex_lock(result + 320);
    if ( (a2 & 1) != 0 )
    {
      for ( i = *(_QWORD **)(v2 + 304); i != (_QWORD *)(v2 + 304); i = (_QWORD *)*i )
      {
        v5 = (void (__fastcall *)(__int64, __int64))*(i - 2);
        if ( v5 )
        {
          v6 = *(i - 1);
          if ( *((_DWORD *)v5 - 1) != -538254584 )
            __break(0x8228u);
          v5(v6, 1);
        }
      }
      for ( j = *(__int64 **)(v2 + 288); j != (__int64 *)(v2 + 288); j = (__int64 *)*j )
      {
        if ( *(j - 44) )
        {
          mutex_lock(j - 6);
          put_iova(j - 74);
          *((_BYTE *)j + 57) = 1;
          mutex_unlock(j - 6);
        }
      }
    }
    else
    {
      v7 = (_QWORD *)(v2 + 288);
      while ( 1 )
      {
        v7 = (_QWORD *)*v7;
        if ( v7 == (_QWORD *)(v2 + 288) )
          break;
        if ( (unsigned int)msm_gem_get_iova((__int64)(v7 - 74), v2, v12) )
          goto LABEL_26;
      }
      for ( k = *(_QWORD **)(v2 + 304); k != (_QWORD *)(v2 + 304); k = (_QWORD *)*k )
      {
        v10 = (_DWORD *)*(k - 2);
        if ( v10 )
        {
          v11 = *(k - 1);
          if ( *(v10 - 1) != -538254584 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v10)(v11, 0);
        }
      }
    }
LABEL_26:
    result = mutex_unlock(v2 + 320);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
