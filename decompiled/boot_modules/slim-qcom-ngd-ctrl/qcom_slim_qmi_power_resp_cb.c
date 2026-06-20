__int64 __fastcall qcom_slim_qmi_power_resp_cb(__int64 a1, __int64 a2, __int64 a3, _WORD *a4)
{
  __int64 v5; // x19

  if ( *a4 )
  {
    v5 = a3;
    printk(&unk_C978, (unsigned __int16)*a4);
    a3 = v5;
  }
  return complete(a3 + 16);
}
