__int64 __fastcall cnss_utils_mac_show(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w8
  unsigned int v4; // w8

  v1 = *(_QWORD *)(a1 + 128);
  if ( *(_DWORD *)(v1 + 416) )
  {
    seq_write(a1, "\nProvisioned MAC addresseses\n", 29);
    if ( *(_DWORD *)(v1 + 416) )
    {
      seq_printf(
        a1,
        "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
        (unsigned __int8)*(_DWORD *)(v1 + 392),
        BYTE1(*(_DWORD *)(v1 + 392)),
        (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 392)),
        HIBYTE(*(_DWORD *)(v1 + 392)),
        (unsigned __int8)*(_WORD *)(v1 + 396),
        HIBYTE(*(unsigned __int16 *)(v1 + 396)));
      if ( *(_DWORD *)(v1 + 416) > 1u )
      {
        seq_printf(
          a1,
          "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
          (unsigned __int8)*(_DWORD *)(v1 + 398),
          BYTE1(*(_DWORD *)(v1 + 398)),
          (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 398)),
          HIBYTE(*(_DWORD *)(v1 + 398)),
          (unsigned __int8)*(_WORD *)(v1 + 402),
          HIBYTE(*(unsigned __int16 *)(v1 + 402)));
        if ( *(_DWORD *)(v1 + 416) >= 3u )
        {
          seq_printf(
            a1,
            "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
            (unsigned __int8)*(_DWORD *)(v1 + 404),
            BYTE1(*(_DWORD *)(v1 + 404)),
            (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 404)),
            HIBYTE(*(_DWORD *)(v1 + 404)),
            (unsigned __int8)*(_WORD *)(v1 + 408),
            HIBYTE(*(unsigned __int16 *)(v1 + 408)));
          if ( *(_DWORD *)(v1 + 416) >= 4u )
          {
            seq_printf(
              a1,
              "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
              (unsigned __int8)*(_DWORD *)(v1 + 410),
              BYTE1(*(_DWORD *)(v1 + 410)),
              (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 410)),
              HIBYTE(*(_DWORD *)(v1 + 410)),
              (unsigned __int8)*(_WORD *)(v1 + 414),
              HIBYTE(*(unsigned __int16 *)(v1 + 414)));
            v3 = *(_DWORD *)(v1 + 416);
            if ( v3 >= 5 )
            {
              seq_printf(
                a1,
                "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
                (unsigned __int8)*(_DWORD *)(v1 + 416),
                BYTE1(v3),
                BYTE2(v3),
                HIBYTE(v3),
                (unsigned __int8)*(_WORD *)(v1 + 420),
                HIBYTE(*(unsigned __int16 *)(v1 + 420)));
              if ( *(_DWORD *)(v1 + 416) > 5u )
                goto LABEL_16;
            }
          }
        }
      }
    }
  }
  if ( *(_DWORD *)(v1 + 444) )
  {
    seq_write(a1, "\nDerived MAC addresseses\n", 25);
    if ( *(_DWORD *)(v1 + 444) )
    {
      seq_printf(
        a1,
        "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
        (unsigned __int8)*(_DWORD *)(v1 + 420),
        BYTE1(*(_DWORD *)(v1 + 420)),
        (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 420)),
        HIBYTE(*(_DWORD *)(v1 + 420)),
        (unsigned __int8)*(_WORD *)(v1 + 424),
        HIBYTE(*(unsigned __int16 *)(v1 + 424)));
      if ( *(_DWORD *)(v1 + 444) >= 2u )
      {
        seq_printf(
          a1,
          "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
          (unsigned __int8)*(_DWORD *)(v1 + 426),
          BYTE1(*(_DWORD *)(v1 + 426)),
          (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 426)),
          HIBYTE(*(_DWORD *)(v1 + 426)),
          (unsigned __int8)*(_WORD *)(v1 + 430),
          HIBYTE(*(unsigned __int16 *)(v1 + 430)));
        if ( *(_DWORD *)(v1 + 444) >= 3u )
        {
          seq_printf(
            a1,
            "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
            (unsigned __int8)*(_DWORD *)(v1 + 432),
            BYTE1(*(_DWORD *)(v1 + 432)),
            (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 432)),
            HIBYTE(*(_DWORD *)(v1 + 432)),
            (unsigned __int8)*(_WORD *)(v1 + 436),
            HIBYTE(*(unsigned __int16 *)(v1 + 436)));
          if ( *(_DWORD *)(v1 + 444) >= 4u )
          {
            seq_printf(
              a1,
              "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
              (unsigned __int8)*(_DWORD *)(v1 + 438),
              BYTE1(*(_DWORD *)(v1 + 438)),
              (unsigned __int8)BYTE2(*(_DWORD *)(v1 + 438)),
              HIBYTE(*(_DWORD *)(v1 + 438)),
              (unsigned __int8)*(_WORD *)(v1 + 442),
              HIBYTE(*(unsigned __int16 *)(v1 + 442)));
            v4 = *(_DWORD *)(v1 + 444);
            if ( v4 >= 5 )
            {
              seq_printf(
                a1,
                "MAC_ADDR:%02x:%02x:%02x:%02x:%02x:%02x\n",
                (unsigned __int8)*(_DWORD *)(v1 + 444),
                BYTE1(v4),
                BYTE2(v4),
                HIBYTE(v4),
                (unsigned __int8)*(_WORD *)(v1 + 448),
                HIBYTE(*(unsigned __int16 *)(v1 + 448)));
              if ( *(_DWORD *)(v1 + 444) > 5u )
              {
LABEL_16:
                __break(0x5512u);
                JUMPOUT(0x69FC);
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
