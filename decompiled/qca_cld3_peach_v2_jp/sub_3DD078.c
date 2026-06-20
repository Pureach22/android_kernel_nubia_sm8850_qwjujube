__int64 __fastcall sub_3DD078(__int64 a1, __int64 a2)
{
  __int64 v2; // d8
  __int64 v3; // d24

  *(_QWORD *)(a2 - 480) = v3;
  *(_QWORD *)(a2 - 472) = v2;
  return dot11f_unpack_tlv_primary_device_type(a1, a2 - 480);
}
