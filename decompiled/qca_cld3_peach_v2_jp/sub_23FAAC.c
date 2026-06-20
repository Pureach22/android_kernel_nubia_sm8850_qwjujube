__int64 __fastcall sub_23FAAC(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v6; // w28

  *(_DWORD *)(a6 + 228) = a6;
  *(_DWORD *)(a6 + 232) = v6;
  return wmi_unified_send_multiple_vdev_set_param_cmd();
}
