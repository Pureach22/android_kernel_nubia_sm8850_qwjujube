__int64 __fastcall btfm_slim_status(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w0
  __int64 v3; // x2
  __int64 result; // x0
  unsigned int v5; // w19

  if ( (is_registered & 1) == 0
    && (v1 = *(_QWORD *)(a1 + 152), btfm_slim_get_hwep_details(a1, v1), (v2 = btfm_slim_register_hw_ep(v1)) != 0) )
  {
    v5 = v2;
    printk(&unk_83BB, "btfm_slim_status", v3);
    return v5;
  }
  else
  {
    result = 0;
    is_registered = 1;
  }
  return result;
}
