_DWORD *__fastcall hdd_cm_save_connect_status(_DWORD *result, int a2)
{
  *(_DWORD *)(*(_QWORD *)result + 52404LL) = a2;
  result[209] = a2;
  result[379] = a2;
  return result;
}
