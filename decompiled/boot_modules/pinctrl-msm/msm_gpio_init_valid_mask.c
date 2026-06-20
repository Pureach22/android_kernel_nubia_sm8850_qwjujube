__int64 __fastcall msm_gpio_init_valid_mask(__int64 a1, char *a2, unsigned int a3)
{
  _QWORD *data; // x0
  __int64 v6; // x8
  _QWORD *v7; // x21
  unsigned int *v8; // x8
  unsigned int v9; // w10
  unsigned int v10; // w11
  __int64 v11; // x11
  __int64 v12; // x10
  unsigned __int64 v19; // x12
  __int64 property; // x22
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x8
  unsigned __int64 v26; // x10
  unsigned int u16_array; // w0
  unsigned int v28; // w22
  __int64 result; // x0
  unsigned __int64 v30; // x23
  __int64 v31; // x24
  unsigned int v32; // w25
  unsigned int v33; // w9
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x10
  __int64 v36; // x9
  unsigned __int64 v39; // x11
  unsigned int v40; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v41; // [xsp+8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  data = (_QWORD *)gpiochip_get_data(a1);
  v6 = data[121];
  v7 = data;
  v40 = 0;
  v8 = *(unsigned int **)(v6 + 72);
  if ( v8 )
  {
    v9 = *v8;
    if ( (*v8 & 0x80000000) == 0 )
    {
      v10 = 0;
      while ( v10 < a3 && v9 < a3 )
      {
        v11 = v9 >> 6;
        v12 = 1LL << v9;
        _X11 = (unsigned __int64 *)&a2[8 * v11];
        __asm { PRFM            #0x11, [X11] }
        do
          v19 = __ldxr(_X11);
        while ( __stxr(v19 & ~v12, _X11) );
        v10 = v40 + 1;
        v40 = v10;
        v9 = v8[v10];
        if ( (v9 & 0x80000000) != 0 )
          goto LABEL_23;
      }
LABEL_35:
      dev_err(*v7, "invalid list of reserved GPIOs\n");
      result = 4294967274LL;
      goto LABEL_24;
    }
LABEL_23:
    result = 0;
    goto LABEL_24;
  }
  if ( (int)of_property_count_elems_of_size(*(_QWORD *)(*data + 744LL), "qcom,gpios-reserved", 4) >= 1 )
  {
    memset(a2, 255, ((a3 + 63) >> 3) & 0x1FFFFFF8);
    property = of_find_property(*(_QWORD *)(*v7 + 744LL), "qcom,gpios-reserved", 0);
    v21 = of_prop_next_u32(property, 0, &v40);
    if ( v21 )
    {
      v22 = v21;
      while ( v40 < a3 )
      {
        v23 = 1LL << v40;
        _X9 = (unsigned __int64 *)&a2[8 * ((unsigned __int64)v40 >> 6)];
        __asm { PRFM            #0x11, [X9] }
        do
          v26 = __ldxr(_X9);
        while ( __stxr(v26 & ~v23, _X9) );
        v22 = of_prop_next_u32(property, v22, &v40);
        if ( !v22 )
          goto LABEL_20;
      }
      goto LABEL_35;
    }
  }
LABEL_20:
  u16_array = device_property_read_u16_array(*v7, "gpios", 0, 0);
  if ( (u16_array & 0x80000000) != 0 )
    goto LABEL_23;
  v28 = u16_array;
  if ( u16_array <= a3 )
  {
    v30 = 2 * u16_array;
    v31 = _kmalloc_noprof(v30, 3264);
    if ( v31 )
    {
      v32 = device_property_read_u16_array(*v7, "gpios", v31, v28);
      if ( (v32 & 0x80000000) != 0 )
      {
        dev_err(*v7, "could not read list of GPIOs\n");
      }
      else
      {
        memset(a2, 0, ((a3 + 63) >> 3) & 0x1FFFFFF8);
        v40 = 0;
        if ( v28 )
        {
          v33 = 0;
          do
          {
            if ( v30 <= 2 * (unsigned __int64)v33 )
              __break(1u);
            v34 = *(unsigned __int16 *)(v31 + 2LL * v33);
            v35 = v34 >> 6;
            v36 = 1LL << v34;
            _X10 = (unsigned __int64 *)&a2[8 * v35];
            __asm { PRFM            #0x11, [X10] }
            do
              v39 = __ldxr(_X10);
            while ( __stxr(v39 | v36, _X10) );
            v33 = ++v40;
          }
          while ( v40 < v28 );
        }
      }
      kfree(v31);
      result = v32;
    }
    else
    {
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
