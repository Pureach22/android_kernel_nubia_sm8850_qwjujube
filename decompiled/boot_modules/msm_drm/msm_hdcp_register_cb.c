__int64 __fastcall msm_hdcp_register_cb(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  void *v4; // x0

  if ( !result )
  {
    v4 = &unk_241618;
    return printk(v4, "msm_hdcp_register_cb");
  }
  v3 = *(_QWORD *)(result + 152);
  if ( !v3 )
  {
    v4 = &unk_2339E9;
    return printk(v4, "msm_hdcp_register_cb");
  }
  *(_QWORD *)(v3 + 840) = a3;
  *(_QWORD *)(v3 + 832) = a2;
  return result;
}
