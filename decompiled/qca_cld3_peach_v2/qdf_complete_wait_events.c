__int64 qdf_complete_wait_events()
{
  __int64 result; // x0
  __int64 i; // x1
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x22
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  result = qdf_list_empty(&qdf_wait_event_list);
  if ( (result & 1) == 0 )
  {
    raw_spin_lock(&qdf_wait_event_lock);
    qdf_list_peek_front(&qdf_wait_event_list, v5);
    for ( i = v5[0]; v5[0]; i = v5[0] )
    {
      v2 = *(_QWORD *)(i + 16);
      if ( (*(_BYTE *)(v2 + 36) & 1) == 0 )
      {
        *(_BYTE *)(v2 + 37) = 1;
        v3 = *(_QWORD *)(i + 16);
        if ( v3 )
        {
          if ( *(_DWORD *)(v3 + 32) == 305402420 )
          {
            *(_BYTE *)(v3 + 36) = 1;
            v4 = i;
            complete(v3, i);
            i = v4;
          }
        }
      }
      if ( (unsigned int)qdf_list_peek_next(&qdf_wait_event_list, i, v5) )
        break;
    }
    result = raw_spin_unlock(&qdf_wait_event_lock);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
