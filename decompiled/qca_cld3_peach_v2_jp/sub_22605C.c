__int64 __fastcall sub_22605C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9

  return send_vdev_start_cmd_tlv(a1, a2, a3, a4, a5, a6, v6 ^ 0xFFFFF000000000LL);
}
