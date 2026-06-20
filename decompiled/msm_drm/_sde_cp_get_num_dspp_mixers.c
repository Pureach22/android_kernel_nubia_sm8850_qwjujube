__int64 __fastcall sde_cp_get_num_dspp_mixers(__int64 a1)
{
  int v1; // w9
  unsigned int v2; // w8

  v1 = *(_DWORD *)(a1 + 2192);
  if ( !v1 )
    return 0;
  if ( (unsigned int)(v1 - 9) < 0xFFFFFFF8 )
  {
    __break(0x5512u);
    return sde_cp_crtc_init(a1);
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 2216) != 0;
    if ( v1 != 1 )
    {
      if ( *(_QWORD *)(a1 + 2264) )
        ++v2;
      if ( v1 != 2 )
      {
        if ( *(_QWORD *)(a1 + 2312) )
          ++v2;
        if ( v1 != 3 )
        {
          if ( *(_QWORD *)(a1 + 2360) )
            ++v2;
          if ( v1 != 4 )
          {
            if ( *(_QWORD *)(a1 + 2408) )
              ++v2;
            if ( v1 != 5 )
            {
              if ( *(_QWORD *)(a1 + 2456) )
                ++v2;
              if ( v1 != 6 )
              {
                if ( *(_QWORD *)(a1 + 2504) )
                  ++v2;
                if ( v1 != 7 )
                {
                  if ( *(_QWORD *)(a1 + 2552) )
                    ++v2;
                }
              }
            }
          }
        }
      }
    }
    return v2;
  }
}
