__int64 __fastcall tgt_if_regulatory_send_ctl_info(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x8
  __int64 v3; // x0

  if ( a1 && (v2 = *(_QWORD *)(a1 + 2800)) != 0 && (v3 = *(_QWORD *)(v2 + 16)) != 0 )
    return wmi_unified_send_regdomain_info_to_fw_cmd(
             v3,
             *a2,
             *((unsigned __int16 *)a2 + 2),
             *((unsigned __int16 *)a2 + 3),
             *((unsigned __int8 *)a2 + 8),
             *((unsigned __int8 *)a2 + 9));
  else
    return 16;
}
