__int64 __fastcall qdf_cpuhp_on_down(unsigned int a1)
{
  __int64 result; // x0
  _QWORD *v3; // x1
  _DWORD *v4; // x8
  __int64 v5; // x0
  _QWORD v6[2]; // [xsp+0h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  qdf_mutex_acquire((__int64)&qdf_cpuhp_lock);
  if ( !(unsigned int)qdf_list_peek_front(&qdf_cpuhp_handlers, v6) )
  {
    do
    {
      v3 = (_QWORD *)v6[0];
      v4 = *(_DWORD **)(v6[0] + 32LL);
      if ( v4 )
      {
        v5 = *(_QWORD *)(v6[0] + 16LL);
        if ( *(v4 - 1) != -1783303382 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v4)(v5, a1);
        v3 = (_QWORD *)v6[0];
      }
    }
    while ( !(unsigned int)qdf_list_peek_next(&qdf_cpuhp_handlers, v3, v6) );
  }
  result = qdf_mutex_release((__int64)&qdf_cpuhp_lock);
  _ReadStatusReg(SP_EL0);
  return result;
}
