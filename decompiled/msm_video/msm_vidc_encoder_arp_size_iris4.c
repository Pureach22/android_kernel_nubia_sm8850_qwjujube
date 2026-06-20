__int64 __fastcall msm_vidc_encoder_arp_size_iris4(__int64 a1)
{
  unsigned int v1; // w19

  if ( *(_QWORD *)(a1 + 35936) )
    v1 = 409600;
  else
    v1 = 204800;
  if ( a1 && (msm_vidc_debug & 4) != 0 )
    printk(&unk_8FA63, "low ", a1 + 340, "msm_vidc_encoder_arp_size_iris4", v1);
  return v1;
}
