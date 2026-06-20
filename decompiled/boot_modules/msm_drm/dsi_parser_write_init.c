__int64 __fastcall dsi_parser_write_init(__int64 a1, int a2, unsigned __int64 a3, _QWORD *a4)
{
  char *v4; // x19
  __int64 result; // x0
  size_t v6; // x20
  size_t v8; // x22
  _QWORD *v9; // x8
  __int64 v10; // x20
  const void *v11; // x21
  _BYTE *head_node; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v14; // [xsp+10h] [xbp-20h]
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(char **)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      result = 0;
    }
    else
    {
      if ( a3 >= 0x1F )
        v6 = 31;
      else
        v6 = a3;
      v15 = 0;
      v16 = 0;
      *(_QWORD *)s = 0;
      v14 = 0;
      _check_object_size(s, v6, 0);
      v8 = v6;
      if ( !inline_copy_from_user_9((int)s, a2, v6) )
      {
        s[v6] = 0;
        if ( sscanf(s, "%31s", v4 + 40) == 1 )
        {
          release_firmware(*(_QWORD *)v4);
          if ( (unsigned int)request_firmware(v4, v4 + 40, *((_QWORD *)v4 + 3)) )
          {
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: couldn't read firmware\n");
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to read file\n");
          }
          else
          {
            v9 = *(_QWORD **)v4;
            if ( *(_QWORD *)v4 )
            {
              v10 = *v9;
              v11 = (const void *)v9[1];
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: file %s: size %zd\n", v4 + 40, *v9);
            }
            else
            {
              drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: couldn't read firmware\n");
              LODWORD(v10) = 0;
              v11 = nullptr;
            }
            dsi_parser_free_mem(*((_QWORD *)v4 + 3), *((_QWORD *)v4 + 1));
            if ( *((_QWORD *)v4 + 4) )
            {
              devm_kfree(*((_QWORD *)v4 + 3));
              *((_QWORD *)v4 + 4) = 0;
            }
            head_node = dsi_parser_get_head_node(v4, v11, v10);
            *((_QWORD *)v4 + 1) = head_node;
            if ( !head_node )
              drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to parse data\n");
          }
        }
        else
        {
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get val\n");
        }
      }
      result = v8;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
