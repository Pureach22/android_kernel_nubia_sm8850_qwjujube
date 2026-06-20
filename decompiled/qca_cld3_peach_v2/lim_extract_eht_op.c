__int64 __fastcall lim_extract_eht_op(__int64 result, __int64 a2)
{
  _BYTE *v2; // x19
  __int64 v3; // x20
  void *v4; // x0
  unsigned int v5; // w8
  char v6; // w9

  v2 = (_BYTE *)(result + 7174);
  if ( *(_BYTE *)(result + 10071) == 1 && *(_BYTE *)(a2 + 2832) && (*(_BYTE *)(a2 + 2833) & 1) != 0 )
  {
    v3 = result;
    v4 = qdf_mem_copy((void *)(result + 10164), (const void *)(a2 + 2832), 0xCu);
    result = wma_get_eht_ch_width(v4);
    v5 = v2[2996] & 7;
    if ( v5 <= 2 )
    {
      if ( v5 != 1 && v5 != 2 )
        goto LABEL_13;
LABEL_17:
      *(_DWORD *)(v3 + 7176) = v5;
      goto LABEL_18;
    }
    if ( v5 == 3 )
    {
      if ( (unsigned int)result < 2 )
        goto LABEL_16;
    }
    else
    {
      if ( v5 != 4 )
      {
LABEL_13:
        *(_DWORD *)(v3 + 7176) = 0;
LABEL_18:
        v6 = v2[2998];
        *v2 = v2[2997];
        v2[12] = v6;
        return result;
      }
      if ( (_DWORD)result != 2 )
      {
        if ( (_DWORD)result == 4 )
        {
          v5 = 7;
          goto LABEL_17;
        }
LABEL_16:
        v5 = 2;
        goto LABEL_17;
      }
    }
    v5 = 3;
    goto LABEL_17;
  }
  return result;
}
