__int64 __fastcall qmi_data_ready(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 648);
  if ( v1 )
    return queue_work_on(32, *(_QWORD *)(v1 + 104), v1 + 72);
  return result;
}
