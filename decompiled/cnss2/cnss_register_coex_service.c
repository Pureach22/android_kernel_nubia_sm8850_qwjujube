__int64 __fastcall cnss_register_coex_service(__int64 a1)
{
  __int64 result; // x0

  result = qmi_handle_init(a1 + 6760, 8204, coex_qmi_ops, 0);
  if ( (result & 0x80000000) == 0 )
    return qmi_add_lookup(a1 + 6760, 34, 1, 0);
  return result;
}
