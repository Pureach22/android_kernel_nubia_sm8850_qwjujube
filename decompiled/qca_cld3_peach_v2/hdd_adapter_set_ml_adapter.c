__int64 __fastcall hdd_adapter_set_ml_adapter(__int64 result)
{
  *(_DWORD *)(result + 52800) |= 1u;
  return result;
}
