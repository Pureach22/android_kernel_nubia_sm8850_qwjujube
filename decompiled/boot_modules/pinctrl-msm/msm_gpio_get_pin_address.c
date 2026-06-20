__int64 __fastcall msm_gpio_get_pin_address(int a1, _QWORD *a2)
{
  __int64 v3; // x20
  unsigned int v4; // w21
  char is_valid; // w8
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x21
  __int64 v10; // x8
  __int64 *resource_byname; // x0
  __int64 v12; // x8
  __int64 v13; // x8
  int v14; // w9

  if ( !msm_pinctrl_data )
  {
    printk(&unk_D54F, a2);
    return 0;
  }
  v3 = *(_QWORD *)msm_pinctrl_data;
  v4 = a1 - *(_DWORD *)(msm_pinctrl_data + 184);
  is_valid = gpiochip_line_is_valid(msm_pinctrl_data + 16, v4);
  result = 0;
  if ( a2 && (is_valid & 1) != 0 )
  {
    v7 = v3 - 16;
    v8 = *(_QWORD *)(msm_pinctrl_data + 968);
    v9 = *(_QWORD *)(v8 + 32) + 112LL * v4;
    v10 = *(_QWORD *)(v8 + 56);
    if ( v10 )
    {
      resource_byname = (__int64 *)platform_get_resource_byname(
                                     v7,
                                     512,
                                     *(_QWORD *)(v10 + 8 * ((*(_QWORD *)(v9 + 84) >> 5) & 3LL)));
      if ( resource_byname )
      {
LABEL_6:
        v12 = *resource_byname;
        result = 1;
        v13 = v12 + *(unsigned int *)(v9 + 60);
        *a2 = v13;
        if ( (*(_DWORD *)(v9 + 84) & 0x1E) != 0 )
          v14 = *(_DWORD *)(v9 + 84) & 0x1F;
        else
          v14 = 1;
        a2[1] = v13 + (unsigned int)(v14 << 12) - 1;
        return result;
      }
    }
    else
    {
      resource_byname = (__int64 *)platform_get_resource(v7, 512, 0);
      if ( resource_byname )
        goto LABEL_6;
    }
    dev_err(v3, "failed to get resource\n");
    return 0;
  }
  return result;
}
