__int64 __fastcall sub_21A1F4(__int64 a1, __int64 a2, __int64 a3)
{
  int v3; // w17

  if ( v3 )
    JUMPOUT(0x22764C);
  return wmi_unified_pdev_pb_mem_ind_send(a1, a2, a3);
}
