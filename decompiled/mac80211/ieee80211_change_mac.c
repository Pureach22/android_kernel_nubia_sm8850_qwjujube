__int64 __fastcall ieee80211_change_mac(__int64 a1, unsigned __int8 *a2)
{
  __int64 v2; // x24
  __int64 v5; // x20
  _QWORD *v6; // x21
  __int64 v7; // x25
  int v8; // w8
  int v9; // w8
  unsigned int v10; // w23
  __int64 v11; // x9
  unsigned __int64 v12; // x11
  __int64 *v13; // x8
  unsigned __int64 v14; // x11
  int v15; // w9
  __int16 v16; // w10
  __int64 **i; // x8

  if ( *(_BYTE *)(*(_QWORD *)(a1 + 992) + 67LL) == 1 )
  {
    v2 = *(_QWORD *)(a1 + 4304);
    v5 = a1 + 2688;
    mutex_lock(*(_QWORD *)(v2 + 72));
    v6 = *(_QWORD **)(a1 + 4304);
    v7 = *(_QWORD *)(a1 + 4320);
    if ( (v7 & 1) == 0 )
    {
      v8 = *(_DWORD *)(a1 + 7408);
      goto LABEL_4;
    }
    if ( (*(_QWORD *)(*(_QWORD *)(a1 + 4296) + 168LL) & 4) != 0 )
    {
      for ( i = (__int64 **)v6[658]; i != v6 + 658; i = (__int64 **)*i )
      {
        if ( i[2] == (__int64 *)v5 && ((_BYTE)i[4] & 1) != 0 )
          goto LABEL_8;
      }
      if ( v6[587] )
      {
        if ( v6[621] == v5 )
          v10 = -16;
        else
          v10 = 0;
      }
      else
      {
        v10 = 0;
      }
      v8 = *(_DWORD *)(a1 + 7408);
      if ( v8 == 8 || v8 == 2 )
      {
        if ( !v10 )
        {
LABEL_4:
          if ( v8 == 6 )
            v9 = (*(unsigned __int8 *)(a1 + 4952) >> 6) & 1;
          else
            v9 = 1;
          v11 = v6[9];
          v12 = *(unsigned int *)(v11 + 54);
          if ( (unsigned int)v12 | *(unsigned __int16 *)(v11 + 58) && v9 && (v13 = (__int64 *)v6[577], v13 != v6 + 577) )
          {
            v14 = ~((bswap64(v12) >> 16) & 0xFFFFFFFFFFFF00FFLL
                  | ((unsigned __int64)(unsigned __int8)*(_WORD *)(v11 + 58) << 8)
                  | HIBYTE(*(unsigned __int16 *)(v11 + 58)));
            while ( v13 == (__int64 *)v5
                 || *((_DWORD *)v13 + 1180) == 6 && (v13[283] & 0x40) == 0
                 || (((((unsigned __int64)*((unsigned __int8 *)v13 + 5842) << 40)
                     | ((unsigned __int64)*((unsigned __int8 *)v13 + 5843) << 32)
                     | ((unsigned __int64)*((unsigned __int8 *)v13 + 5844) << 24)
                     | ((unsigned __int64)*((unsigned __int8 *)v13 + 5845) << 16)
                     | ((unsigned __int64)*((unsigned __int8 *)v13 + 5846) << 8)
                     | *((unsigned __int8 *)v13 + 5847))
                    ^ (((unsigned __int64)a2[2] << 40)
                     | ((unsigned __int64)a2[3] << 32)
                     | ((unsigned __int64)a2[4] << 24)
                     | ((unsigned __int64)a2[5] << 16)
                     | ((unsigned __int64)a2[6] << 8)
                     | a2[7]))
                   & v14) == 0 )
            {
              v13 = (__int64 *)*v13;
              if ( v13 == v6 + 577 )
                goto LABEL_20;
            }
            v10 = -22;
          }
          else
          {
LABEL_20:
            if ( (v7 & 1) != 0 )
              drv_remove_interface(*(_QWORD *)(a1 + 4304), v5);
            v10 = eth_mac_addr(*(_QWORD *)(a1 + 4296), a2);
            if ( !v10 )
            {
              v15 = *(_DWORD *)(a2 + 2);
              v16 = *((_WORD *)a2 + 3);
              *(_DWORD *)(a1 + 8530) = v15;
              *(_WORD *)(a1 + 8534) = v16;
              *(_DWORD *)(a1 + 7524) = v15;
              *(_WORD *)(a1 + 7528) = v16;
            }
            if ( (v7 & 1) != 0 && (unsigned int)drv_add_interface((__int64)v6, v5) )
              __break(0x800u);
          }
        }
      }
      else
      {
        v10 = -95;
      }
    }
    else
    {
LABEL_8:
      v10 = -16;
    }
    mutex_unlock(*(_QWORD *)(v2 + 72));
    return v10;
  }
  return 0;
}
