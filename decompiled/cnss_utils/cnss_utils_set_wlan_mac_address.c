__int64 __fastcall cnss_utils_set_wlan_mac_address(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  unsigned int v3; // w8

  v2 = cnss_utils_priv;
  if ( !cnss_utils_priv )
    return 4294967274LL;
  if ( !(_DWORD)a2 || (unsigned int)a2 % 6 )
  {
    printk(&unk_71D7, a2);
    return 4294967274LL;
  }
  else if ( (unsigned int)a2 >= 0x1E )
  {
    printk(&unk_71F8, 4);
    return 4294967274LL;
  }
  else
  {
    v3 = *(_DWORD *)(cnss_utils_priv + 416);
    if ( v3 )
    {
      printk(&unk_7486, v3);
    }
    else
    {
      *(_DWORD *)(cnss_utils_priv + 416) = (unsigned int)a2 / 6;
      if ( (unsigned int)a2 >= 6 )
      {
        *(_DWORD *)(v2 + 392) = *(_DWORD *)a1;
        *(_WORD *)(v2 + 396) = *(_WORD *)(a1 + 4);
        if ( (unsigned int)(a2 - 6) >= 6 )
        {
          *(_DWORD *)(v2 + 398) = *(_DWORD *)(a1 + 6);
          *(_WORD *)(v2 + 402) = *(_WORD *)(a1 + 10);
          if ( (unsigned int)(a2 - 12) >= 6 )
          {
            *(_DWORD *)(v2 + 404) = *(_DWORD *)(a1 + 12);
            *(_WORD *)(v2 + 408) = *(_WORD *)(a1 + 16);
            if ( (unsigned int)(a2 - 18) >= 6 )
            {
              *(_DWORD *)(v2 + 410) = *(_DWORD *)(a1 + 18);
              *(_WORD *)(v2 + 414) = *(_WORD *)(a1 + 22);
              return 0;
            }
          }
        }
      }
    }
    return 0;
  }
}
