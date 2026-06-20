__int64 __fastcall get_mbox_num_chans(__int64 a1)
{
  __int64 node_with_property; // x0
  __int64 v3; // x20
  unsigned int v4; // w25
  int v5; // w0
  int v6; // w23
  unsigned int v7; // w24
  _QWORD v9[11]; // [xsp+8h] [xbp-58h] BYREF

  v9[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v9, 0, 80);
  node_with_property = of_find_node_with_property(0, "mboxes");
  if ( node_with_property )
  {
    v3 = node_with_property;
    v4 = 0;
    do
    {
      if ( (of_device_is_available(v3) & 1) != 0 )
      {
        v5 = of_count_phandle_with_args(v3, "mboxes", "#mbox-cells");
        if ( v5 >= 1 )
        {
          v6 = v5;
          v7 = 0;
          while ( (unsigned int)_of_parse_phandle_with_args(v3, "mboxes", "#mbox-cells", 0xFFFFFFFFLL, v7, v9)
               || v9[0] != a1 )
          {
            if ( v6 == ++v7 )
              goto LABEL_3;
          }
          ++v4;
        }
      }
LABEL_3:
      v3 = of_find_node_with_property(v3, "mboxes");
    }
    while ( v3 );
  }
  else
  {
    v4 = 0;
  }
  _ReadStatusReg(SP_EL0);
  if ( v4 <= 1 )
    return 1;
  else
    return v4;
}
