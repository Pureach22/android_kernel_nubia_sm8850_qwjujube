__int64 __fastcall cser_set_inst_name(__int64 a1, char *s)
{
  size_t v4; // x0
  size_t v5; // x21
  const char *v6; // x0
  __int64 v7; // x3
  unsigned __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x0
  __int64 v11; // x3
  char *v12; // x0
  __int64 v13; // x2
  __int64 v14; // x3
  int v15; // w21
  __int64 v16; // x3
  unsigned __int64 v17; // x20
  unsigned int v18; // w0
  __int64 v19; // x3
  __int64 v20; // x2
  __int64 v21; // x3
  int v22; // w0
  int v23; // w22
  __int64 v24; // x1
  const char *v25; // x0
  char v26; // w8
  void *v27; // x0
  __int64 v28; // x0
  __int64 v29; // x3
  int v30; // w10
  __int64 v31; // x8
  int v32; // w9
  int v33; // w0
  __int64 v34; // x3
  __int64 v35; // x2
  __int64 v36; // x3
  unsigned int v37; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = strlen(s);
  v5 = v4 + 1;
  if ( v4 + 1 > 0xF )
    goto LABEL_4;
  v6 = (const char *)strnchr(s, v4, 46);
  if ( !v6 )
  {
    printk(&unk_935C, "cser_set_inst_name", s, v7);
    result = 4294967274LL;
    goto LABEL_5;
  }
  v8 = v5 - strlen(v6);
  if ( v8 > 5 )
  {
LABEL_4:
    result = 4294967260LL;
    goto LABEL_5;
  }
  v10 = kstrndup(s, v8 - 1, 3264);
  if ( !v10 )
  {
    printk(&unk_8E67, "cser_set_inst_name", 0, v11);
    result = 4294967284LL;
    goto LABEL_5;
  }
  *(_QWORD *)(a1 + 184) = v10;
  v12 = strrchr(s, 46);
  if ( !v12 )
  {
    v27 = &unk_92AE;
LABEL_34:
    printk(v27, "cser_set_inst_name", v13, v14);
    result = 4294967274LL;
    goto LABEL_5;
  }
  *v12 = 0;
  if ( (unsigned int)kstrtou8(v12 + 1, 0, a1 + 192) )
  {
    v27 = &unk_8BD5;
    goto LABEL_34;
  }
  v15 = *(unsigned __int8 *)(a1 + 192);
  v17 = _kmalloc_cache_noprof(strnchr, 3520, 1616);
  if ( !v17 )
    goto LABEL_39;
  mutex_lock(&chardev_ida_lock);
  if ( !qword_158 )
  {
    v37 = 0;
    v18 = alloc_chrdev_region(&v37, 0, 4, "msm_usb_bridge");
    if ( v18 )
    {
      v23 = v18;
      printk(&unk_9227, "usb_cser_alloc_chardev_region", v18, v19);
      mutex_unlock(&chardev_ida_lock);
      printk(&unk_9008, "f_cdev_alloc", v35, v36);
      goto LABEL_25;
    }
    minors = 1;
    major = v37 >> 20;
    fcdev_classp = class_create("msm_usb_bridge");
    if ( (unsigned __int64)fcdev_classp >= 0xFFFFFFFFFFFFF001LL )
      printk(&unk_8BFE, "usb_cser_alloc_chardev_region", v20, v21);
  }
  v22 = ida_alloc_range(&chardev_ida, 0, 0xFFFFFFFFLL, 3264);
  if ( v22 >= 4 )
  {
    ida_free(&chardev_ida, (unsigned int)v22);
    mutex_unlock(&chardev_ida_lock);
    v23 = -19;
    goto LABEL_16;
  }
  *(_DWORD *)(v17 + 1048) = v15;
  *(_DWORD *)(v17 + 1064) = v22;
  mutex_unlock(&chardev_ida_lock);
  snprintf((char *)(v17 + 1052), 9u, "%s%d", "at_usb", v15);
  *(_DWORD *)(v17 + 1068) = 0;
  _init_waitqueue_head(v17 + 1072, "&port->open_wq", &f_cdev_alloc___key);
  _init_waitqueue_head(v17 + 1096, "&port->read_wq", &f_cdev_alloc___key_26);
  *(_QWORD *)(v17 + 1120) = v17 + 1120;
  *(_QWORD *)(v17 + 1128) = v17 + 1120;
  *(_QWORD *)(v17 + 1136) = v17 + 1136;
  *(_QWORD *)(v17 + 1144) = v17 + 1136;
  *(_QWORD *)(v17 + 1152) = v17 + 1152;
  *(_QWORD *)(v17 + 1160) = v17 + 1152;
  v28 = alloc_workqueue(&unk_8E78, 393226, 1, v17 + 1052);
  *(_QWORD *)(v17 + 1552) = v28;
  if ( !v28 )
  {
    printk(&unk_90DB, "f_cdev_alloc", v17 + 1052, v29);
    v23 = -12;
    goto LABEL_16;
  }
  cdev_init(v17, &f_cdev_fops);
  device_initialize(v17 + 136);
  v30 = *(_DWORD *)(v17 + 1064);
  v31 = fcdev_classp;
  v32 = major;
  *(_QWORD *)(v17 + 232) = 0;
  *(_QWORD *)(v17 + 928) = v31;
  *(_QWORD *)(v17 + 944) = cdev_device_release;
  *(_DWORD *)(v17 + 896) = v30 | (v32 << 20);
  dev_set_name(v17 + 136, v17 + 1052);
  v33 = cdev_device_add(v17, v17 + 136);
  if ( !v33 )
  {
    usb_cser_debugfs_init(v17);
    printk(&unk_8CC1, "f_cdev_alloc", v17 + 1052, v17);
    if ( v17 < 0xFFFFFFFFFFFFF001LL )
      goto LABEL_26;
LABEL_39:
    printk(&unk_8F3C, "cser_set_inst_name", *(unsigned __int8 *)(a1 + 192), v16);
    result = 4294967284LL;
    goto LABEL_5;
  }
  v23 = v33;
  printk(&unk_8C7D, "f_cdev_alloc", v17 + 1052, v34);
  destroy_workqueue(*(_QWORD *)(v17 + 1552));
LABEL_16:
  if ( !qword_158 )
  {
    if ( major )
    {
      if ( minors )
        v24 = 4;
      else
        v24 = 0;
      unregister_chrdev_region((unsigned int)(major << 20), v24);
      minors = 0;
      major = 0;
    }
    if ( fcdev_classp && (unsigned __int64)fcdev_classp <= 0xFFFFFFFFFFFFF000LL )
      class_destroy();
  }
LABEL_25:
  kfree(v17);
  v17 = v23;
  if ( (unsigned __int64)v23 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_39;
LABEL_26:
  v25 = *(const char **)(a1 + 184);
  *(_QWORD *)(a1 + 176) = v17;
  result = strcmp(v25, "dun");
  if ( (_DWORD)result )
  {
    result = 0;
    v26 = 96;
  }
  else
  {
    *(_QWORD *)(v17 + 1488) = dun_cser_connect;
    *(_QWORD *)(v17 + 1472) = dun_cser_get_dtr;
    *(_QWORD *)(v17 + 1480) = dun_cser_get_rts;
    *(_QWORD *)(v17 + 1512) = dun_cser_send_carrier_detect;
    *(_QWORD *)(v17 + 1520) = dun_cser_send_ring_indicator;
    *(_QWORD *)(v17 + 1528) = dun_cser_send_ctrl_bits;
    *(_QWORD *)(v17 + 1496) = dun_cser_disconnect;
    *(_QWORD *)(v17 + 1504) = dun_cser_send_break;
    v26 = 64;
  }
  *(_BYTE *)(a1 + 193) = v26;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
