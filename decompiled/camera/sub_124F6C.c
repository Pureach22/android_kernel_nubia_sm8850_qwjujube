__int64 __fastcall sub_124F6C(__int64 a1)
{
  __int64 v1; // x22

  if ( (v1 & 0x80000000000LL) != 0 )
    JUMPOUT(0x120B04);
  return cam_align_dma_buf_size(a1);
}
