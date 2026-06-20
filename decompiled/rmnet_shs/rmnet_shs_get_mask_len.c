__int64 __fastcall rmnet_shs_get_mask_len(char a1)
{
  return (unsigned __int8)((a1 & 1)
                         + ((a1 & 2) != 0)
                         + ((a1 & 4) != 0)
                         + ((a1 & 8) != 0)
                         + ((a1 & 0x10) != 0)
                         + ((a1 & 0x20) != 0)
                         + ((a1 & 0x40) != 0)
                         + ((unsigned __int8)(a1 & 0x80) >> 7));
}
