__int64 ipahal_pkt_status_get_size()
{
  if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
  {
    __break(0x5512u);
    __asm { PRFM            #0x17, loc_16A67C }
    JUMPOUT(0x182994);
  }
  return ipahal_pkt_status_objs[10 * *(unsigned int *)ipahal_ctx];
}
