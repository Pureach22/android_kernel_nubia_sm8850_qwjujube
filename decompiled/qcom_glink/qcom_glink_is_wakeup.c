__int64 __fastcall qcom_glink_is_wakeup(char a1)
{
  unsigned int v1; // w8

  v1 = (unsigned __int8)glink_resume_pkt;
  if ( glink_resume_pkt == 1 && (a1 & 1) != 0 )
    glink_resume_pkt = 0;
  return v1;
}
