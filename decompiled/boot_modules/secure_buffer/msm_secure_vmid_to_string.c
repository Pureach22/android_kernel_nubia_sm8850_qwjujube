const char *__fastcall msm_secure_vmid_to_string(int a1)
{
  if ( (unsigned int)(a1 + 1) > 0x2C )
    return "Unknown VMID";
  else
    return off_9748[a1 + 1];
}
