__int64 __fastcall hif_send_complete_check(__int64 result, unsigned int a2, int a3)
{
  unsigned __int8 v3; // w19
  __int64 v4; // x20
  unsigned __int16 free_queue_number; // w8

  v3 = a2;
  if ( a3 )
    return ce_per_engine_servicereap(result, v3);
  v4 = result;
  free_queue_number = hif_get_free_queue_number(result, a2);
  result = v4;
  if ( *(_DWORD *)(*(_QWORD *)(v4 + 27400) + 32LL * v3 + 8) >> 1 >= (unsigned int)free_queue_number )
    return ce_per_engine_servicereap(result, v3);
  return result;
}
