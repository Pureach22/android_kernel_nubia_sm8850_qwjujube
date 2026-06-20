__int64 __fastcall reg_chan_opclass_to_freq_prefer_global(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned __int8 *a10,
        unsigned __int8 a11,
        unsigned __int8 a12)
{
  int v12; // w21
  __int64 result; // x0
  int v16; // w22
  char *v17; // x8
  __int64 v18; // x9
  __int64 v19; // x24
  char *class_from_country; // x0
  __int64 v21; // x8
  unsigned __int8 *v22; // x25
  __int64 v23; // x22

  v12 = a12;
  result = 0;
  v16 = a11;
  v17 = &global_op_class;
  switch ( a12 )
  {
    case 0x51u:
      goto LABEL_7;
    case 0x52u:
      v17 = (char *)&unk_AD4380;
      v18 = 16;
      goto LABEL_28;
    case 0x53u:
      v17 = (char *)&unk_AD43E0;
      v18 = 16;
      goto LABEL_28;
    case 0x54u:
      v17 = (char *)&unk_AD4440;
      v18 = 16;
      goto LABEL_28;
    case 0x73u:
      v17 = (char *)&off_AD44A0;
      v18 = 16;
      goto LABEL_28;
    case 0x74u:
      v17 = "t";
      v18 = 16;
      goto LABEL_28;
    case 0x75u:
      v17 = (char *)&unk_AD4560;
      v18 = 16;
      goto LABEL_28;
    case 0x76u:
      v17 = (char *)&off_AD45C0;
      v18 = 16;
      goto LABEL_28;
    case 0x77u:
      v17 = "w";
      v18 = 16;
      goto LABEL_28;
    case 0x78u:
      v17 = (char *)&unk_AD4680;
      v18 = 16;
      goto LABEL_28;
    case 0x79u:
      v17 = (char *)&off_AD46E0;
      v18 = 16;
      goto LABEL_28;
    case 0x7Au:
      v17 = (char *)&unk_AD4740;
      v18 = 16;
      goto LABEL_28;
    case 0x7Bu:
      v17 = (char *)&unk_AD47A0;
      v18 = 16;
      goto LABEL_28;
    case 0x7Du:
      v17 = (char *)&off_AD4800;
      v18 = 16;
      goto LABEL_28;
    case 0x7Eu:
      v17 = (char *)&unk_AD4860;
      v18 = 16;
      goto LABEL_28;
    case 0x7Fu:
      v17 = (char *)&unk_AD48C0;
      v18 = 16;
      goto LABEL_28;
    case 0x80u:
      v17 = (char *)&unk_AD4920;
      v18 = 16;
      goto LABEL_28;
    case 0x81u:
      v17 = (char *)&unk_AD4980;
      v18 = 16;
      goto LABEL_28;
    case 0x82u:
      v17 = (char *)&unk_AD49E0;
      v18 = 16;
      goto LABEL_28;
    case 0x83u:
      v17 = (char *)&off_AD4A40;
      v18 = 16;
      goto LABEL_28;
    case 0x84u:
      v17 = (char *)&unk_AD4AA0;
      v18 = 16;
      goto LABEL_28;
    case 0x85u:
      v17 = (char *)&unk_AD4B00;
      v18 = 16;
      goto LABEL_28;
    case 0x86u:
      v17 = (char *)&unk_AD4B60;
      v18 = 16;
      goto LABEL_28;
    case 0x87u:
      v17 = (char *)&unk_AD4BC0;
      v18 = 16;
      goto LABEL_28;
    case 0x88u:
      v17 = (char *)&off_AD4C20;
      v18 = 16;
      goto LABEL_28;
    case 0x89u:
      v17 = (char *)&unk_AD4C80;
LABEL_7:
      v18 = 16;
      break;
    default:
      goto LABEL_35;
  }
  while ( 1 )
  {
LABEL_28:
    if ( !v17[v18] )
    {
LABEL_31:
      v19 = jiffies;
      if ( reg_chan_opclass_to_freq___last_ticks_12 - jiffies + 125 < 0 )
      {
        v22 = a10;
        qdf_trace_msg(0x51u, 2u, "%s: Channel not found", a1, a2, a3, a4, a5, a6, a7, a8, "reg_chan_opclass_to_freq");
        a10 = v22;
        result = 0;
        reg_chan_opclass_to_freq___last_ticks_12 = v19;
        if ( !v22 )
          return result;
      }
      else
      {
        result = 0;
        if ( !a10 )
          return result;
      }
      goto LABEL_36;
    }
    if ( (unsigned __int8)v17[v18] == a11 )
      break;
    if ( ++v18 == 86 )
      goto LABEL_31;
  }
  result = (unsigned __int16)(*((_WORD *)v17 + 6) + 5 * a11);
LABEL_35:
  if ( !a10 )
    return result;
LABEL_36:
  if ( !(_DWORD)result )
  {
    if ( (unsigned int)(v12 - 131) >= 7 )
      class_from_country = reg_get_class_from_country(a10, a1, a2, a3, a4, a5, a6, a7, a8);
    else
      class_from_country = &global_op_class;
    do
    {
      if ( !*class_from_country )
        break;
      if ( (unsigned __int8)*class_from_country == v12 )
      {
        v21 = 16;
        while ( class_from_country[v21] )
        {
          if ( (unsigned __int8)class_from_country[v21] == v16 )
            return *((_DWORD *)class_from_country + 3) + 5 * (unsigned int)a11;
          if ( ++v21 == 86 )
            break;
        }
      }
      class_from_country += 96;
    }
    while ( class_from_country );
    v23 = jiffies;
    if ( reg_country_chan_opclass_to_freq___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Not found ch %d in op class %d ch list, strict %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "reg_country_chan_opclass_to_freq",
        a11,
        a12,
        1);
      reg_country_chan_opclass_to_freq___last_ticks = v23;
    }
    return 0;
  }
  return result;
}
