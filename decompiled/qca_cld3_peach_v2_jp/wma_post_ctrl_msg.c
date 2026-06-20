__int64 __fastcall wma_post_ctrl_msg(__int64 a1, unsigned __int16 *a2)
{
  return 16
       * (unsigned int)((unsigned int)scheduler_post_message_debug(
                                        0x36u,
                                        0x36u,
                                        54,
                                        a2,
                                        0x35u,
                                        (__int64)"wma_post_ctrl_msg") != 0);
}
