__int64 __fastcall dot11f_unpack_tlv_edca_pifs_param_attr(__int64 a1, char *a2, __int16 a3, _BYTE *a4)
{
  char v4; // w9
  char v5; // w8
  size_t v6; // x2

  *a4 = 1;
  if ( a3 )
  {
    v4 = a3 - 1;
    v5 = *a2;
    v6 = (unsigned __int16)(a3 - 1);
    a4[2] = v4;
    a4[1] = v5;
    if ( (unsigned int)v6 < 5 )
    {
      qdf_mem_copy(a4 + 3, a2 + 1, v6);
      return 0;
    }
    else
    {
      *a4 = 0;
      return 8;
    }
  }
  else
  {
    *a4 = 0;
    return 4;
  }
}
