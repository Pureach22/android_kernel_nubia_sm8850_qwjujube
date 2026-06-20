unsigned int *__fastcall _dump_packet(unsigned int *result)
{
  unsigned int v1; // w22
  unsigned int *v2; // x19
  unsigned int v3; // w23
  unsigned int v4; // w8
  __int64 v5; // x1
  __int64 v6; // x3
  _QWORD v7[13]; // [xsp+8h] [xbp-68h] BYREF

  v7[12] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *result;
  if ( *result )
  {
    v2 = result;
    v3 = 0;
    memset(v7, 0, 96);
    do
    {
      v4 = v3;
      v3 += 32;
      if ( v3 <= v1 )
        v5 = 32;
      else
        v5 = v1 & 0x1F;
      result = (unsigned int *)hex_dump_to_buffer((char *)v2 + v4, v5, 32, 4, v7, 96, 0);
      if ( (msm_cvp_debug & 0x20) != 0 && !msm_cvp_debug_out )
        result = (unsigned int *)printk(&unk_94187, &unk_96215, v7, v6);
    }
    while ( v3 < v1 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
