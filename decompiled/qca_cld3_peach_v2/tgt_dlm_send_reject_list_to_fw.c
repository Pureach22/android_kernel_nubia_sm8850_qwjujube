__int64 __fastcall tgt_dlm_send_reject_list_to_fw(__int64 a1, __int64 a2)
{
  __int64 pdev_obj; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 (__fastcall *v13)(__int64, __int64); // x8
  const char *v15; // x2

  pdev_obj = dlm_get_pdev_obj(a1);
  if ( !pdev_obj )
  {
    v15 = "%s: dlm_priv is NULL";
LABEL_8:
    qdf_trace_msg(0x6Du, 2u, v15, v5, v6, v7, v8, v9, v10, v11, v12, "tgt_dlm_send_reject_list_to_fw");
    return 16;
  }
  v13 = *(__int64 (__fastcall **)(__int64, __int64))(pdev_obj + 88);
  if ( !v13 )
  {
    v15 = "%s: Tx ops not registered, failed to send reject list to FW";
    goto LABEL_8;
  }
  if ( *((_DWORD *)v13 - 1) != -857021281 )
    __break(0x8228u);
  return v13(a1, a2);
}
