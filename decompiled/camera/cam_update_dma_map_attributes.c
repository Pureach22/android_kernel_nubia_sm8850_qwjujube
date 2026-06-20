__int64 __fastcall cam_update_dma_map_attributes(__int64 result, char a2)
{
  if ( (a2 & 4) != 0 )
  {
    *(_QWORD *)(result + 72) |= 0x40000uLL;
    if ( (a2 & 1) == 0 )
    {
LABEL_3:
      if ( (a2 & 2) == 0 )
        return result;
LABEL_7:
      *(_QWORD *)(result + 72) |= 0x20uLL;
      return result;
    }
  }
  else if ( (a2 & 1) == 0 )
  {
    goto LABEL_3;
  }
  *(_QWORD *)(result + 72) |= 0x20000uLL;
  if ( (a2 & 2) != 0 )
    goto LABEL_7;
  return result;
}
