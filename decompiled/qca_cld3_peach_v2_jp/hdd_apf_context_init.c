__int64 __fastcall hdd_apf_context_init(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = a1 + 49152;
  result = qdf_event_create((_DWORD *)(a1 + 52224));
  *(_DWORD *)(v1 + 3136) = 0;
  *(_QWORD *)(v1 + 3144) = 0;
  *(_BYTE *)(v1 + 3112) = 1;
  return result;
}
