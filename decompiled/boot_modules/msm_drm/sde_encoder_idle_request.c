__int64 __fastcall sde_encoder_idle_request(__int64 a1)
{
  if ( a1 )
  {
    sde_encoder_resource_control(a1, 6);
    return 0;
  }
  else
  {
    printk(&unk_246014, "sde_encoder_idle_request");
    return 4294967274LL;
  }
}
