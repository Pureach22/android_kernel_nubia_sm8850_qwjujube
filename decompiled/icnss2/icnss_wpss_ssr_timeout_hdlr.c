__int64 __fastcall icnss_wpss_ssr_timeout_hdlr(__int64 a1)
{
  printk("%sicnss2: Timeout waiting for WPSS SSR notification 0x%lx\n", byte_130B32, *(_QWORD *)(a1 - 4224));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: Timeout waiting for WPSS SSR notification 0x%lx\n",
    (const char *)&unk_12DBF3,
    *(_QWORD *)(a1 - 4224));
  return queue_work_on(32, system_wq, &wpss_ssr_work);
}
